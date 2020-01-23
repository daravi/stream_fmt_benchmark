from conans import ConanFile, CMake, tools
import os


class BenchmarkPlaygroundConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"

    requires = (
        "benchmark/1.5.0",
        "fmt/6.1.2",
        "glog/0.4.0",
    )

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def test(self):
        if not tools.cross_building(self.settings):
            bin_path = os.path.join("bin", "benchmark_playground")
            self.run(bin_path, run_environment=True)