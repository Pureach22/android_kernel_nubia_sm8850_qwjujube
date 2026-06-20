_QWORD *sde_edid_init()
{
  _QWORD *result; // x0
  char v1; // w8
  _QWORD *v2; // x19

  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "%s +\n", "sde_edid_init");
  result = (_QWORD *)_kmalloc_cache_noprof(drm_dp_dpcd_read, 3520, 216);
  if ( result )
  {
    v1 = _drm_debug;
    result[25] = 0;
    result[26] = 0;
    result[23] = 0;
    result[24] = 0;
    result[21] = 0;
    result[22] = 0;
    result[19] = 0;
    result[20] = 0;
    result[17] = 0;
    result[18] = 0;
    result[15] = 0;
    result[16] = 0;
    result[13] = 0;
    result[14] = 0;
    result[11] = 0;
    result[12] = 0;
    result[9] = 0;
    result[10] = 0;
    result[7] = 0;
    result[8] = 0;
    result[5] = 0;
    result[6] = 0;
    result[3] = 0;
    result[4] = 0;
    result[1] = 0;
    result[2] = 0;
    *result = 0;
    if ( (v1 & 4) == 0 )
      return result;
    v2 = result;
    _drm_dev_dbg(0, 0, 0, "%s -\n", "sde_edid_init");
  }
  else
  {
    v2 = nullptr;
    printk(&unk_2324A1, "sde_edid_init");
  }
  return v2;
}
