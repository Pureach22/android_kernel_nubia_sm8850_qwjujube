_QWORD *__fastcall sps_rm_config_init(_QWORD *result)
{
  memset(result + 14, 204, 32);
  memset(result + 10, 204, 32);
  memset(result + 6, 204, 32);
  memset(result + 2, 204, 32);
  *result = 0xCCCCCCCCCCCCCCCCLL;
  result[1] = 0xCCCCCCCCCCCCCCCCLL;
  return result;
}
