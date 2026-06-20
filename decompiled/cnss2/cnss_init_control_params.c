__int64 __fastcall cnss_init_control_params(__int64 *a1)
{
  __int64 v1; // x8
  __int64 result; // x0

  v1 = *a1;
  a1[835] = 0;
  result = of_find_property(*(_QWORD *)(v1 + 760), "qcom,wlan-cbc-enabled", 0);
  a1[836] = 0x1900000000LL;
  a1[837] = 0x100002710LL;
  a1[838] = -4294067296LL;
  *((_BYTE *)a1 + 7488) = result != 0;
  *((_DWORD *)a1 + 1678) = 900000;
  *((_BYTE *)a1 + 7724) = 1;
  return result;
}
