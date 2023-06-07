#pragma once

// scanf 같은 함수들은 안전하지 않기 때문에 경고를 무시하고 사용하기 위해
#define _CRT_SECURE_NO_WARNINGS

// c언어의 표준입출력 헤더
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Files, Base에 선언한 함수에 접근하기 위해 포함
#include "Base/Base.h"
#include "DataType/DataType.h"
#include "Operator/Operator.h"
#include "Conditional/Conditional.h"
#include "Loop/Loop.h"
#include "Arrays/Arrays.h"
#include "Functions/Functions.h"
#include "﻿User-DefinedTypes/﻿User-DefinedTypes.h"
