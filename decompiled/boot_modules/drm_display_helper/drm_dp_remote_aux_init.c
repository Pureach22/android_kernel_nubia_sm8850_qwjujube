_QWORD *__fastcall drm_dp_remote_aux_init(_QWORD *result)
{
  result[165] = 0xFFFFFFFE00000LL;
  result[166] = result + 166;
  result[167] = result + 166;
  result[168] = drm_dp_aux_crc_work;
  return result;
}
