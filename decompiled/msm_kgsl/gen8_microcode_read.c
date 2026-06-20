__int64 __fastcall gen8_microcode_read(_QWORD *a1)
{
  return adreno_get_firmware(a1, *(const char **)(a1[1783] + 96LL), (__int64)(a1 + 1784));
}
