#include <benchmark/benchmark.h>
#include <fmt/core.h>
#include <glog/logging.h>

static void StringToStream(benchmark::State& state) {
  // Perform setup here
  const std::string name{ "Payload" };
  for (auto _ : state) {
    // This code gets timed
    LOG(INFO) << "CoreIPC::Impl::addServer -- Connection '" << name << "' does not exist. Creating.";
  }
}

static void StringToFormatToStream(benchmark::State& state) {
  // Perform setup here
  const std::string name{ "Payload" };
  for (auto _ : state) {
    // This code gets timed
    LOG(INFO) << fmt::format("CoreIPC::Impl::addServer -- Connection '{}' does not exist. Creating.", name);
  }
}

// Register the function as a benchmark
BENCHMARK(StringToStream);
BENCHMARK(StringToFormatToStream);


int main(int argc, char *argv[])
{
    // FLAGS_logtostderr = 1;
    google::InitGoogleLogging(argv[0]);
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
    return 0;
}
