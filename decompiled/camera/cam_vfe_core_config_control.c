_DWORD *__fastcall cam_vfe_core_config_control(_DWORD *result)
{
  _DWORD *v1; // x8

  v1 = *(_DWORD **)(*(_QWORD *)result + 24LL);
  v1[8] = result[3];
  v1[9] = result[4];
  v1[10] = result[5];
  v1[11] = result[6];
  v1[12] = result[7];
  v1[13] = result[8];
  v1[14] = result[13] & 0x10000;
  v1[15] = result[13] & 1;
  return result;
}
