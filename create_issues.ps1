$issues = @(
    "Phase 1: auto, decltype, nullptr, enum class",
    "Phase 1: smart pointers - unique_ptr, shared_ptr",
    "Phase 1: rvalue references and move semantics",
    "Phase 1: lambda expressions and captures",
    "Phase 1: RAII principles with custom classes",
    "Phase 1: STL containers and algorithms with lambdas",
    "Phase 1: Mini project using modern C++11 idioms",
    "Phase 2: if constexpr and constexpr if",
    "Phase 2: std::variant, std::optional, std::any",
    "Phase 2: structured bindings and std::tie",
    "Phase 2: filesystem library",
    "Phase 2: fold expressions",
    "Phase 2: parallel algorithms with std::execution",
    "Phase 3: concepts and template constraints",
    "Phase 3: ranges and views",
    "Phase 3: coroutines",
    "Phase 3: consteval, constinit, constexpr",
    "Phase 3: modules and modular project",
    "Phase 3: std::span and chrono/calendar",
    "Phase 4: std::expected and monadic error handling",
    "Phase 4: explicit object parameter and deducing this",
    "Phase 4: updated range algorithms and pipelines",
    "Phase 4: flat_map, flat_set performance study",
    "Phase 4: mdspan, atomic wait, monadic ops",
    "Phase 5: matrix library using CRTP + expression templates",
    "Phase 5: thread-safe queue with atomics",
    "Phase 5: logger with variadic templates and std::format",
    "Phase 5: inspect and use libc++ or libstdc++",
    "Phase 5: modify and rebuild AOSP C++ module",
    "Phase 5: contribute patch to open-source C++ project"
)
for ($i = 0; $i -lt $issues.Count; $i++) {
    $title = $issues[$i]
    $number = $i + 1
    $phase = ($title -split ' ')[1]
    Write-Output "Creating issue #${number}: ${title}"
    gh issue create --repo SACHIN13T/aosp-cpp-middleware-journey `
        --title "#${number} ${title}" `
        --body "Automated issue for mastering Modern C++ in the context of AOSP C++ middleware journey. Track progress here." `
        --label "phase-${phase}" --label "learning"
}
