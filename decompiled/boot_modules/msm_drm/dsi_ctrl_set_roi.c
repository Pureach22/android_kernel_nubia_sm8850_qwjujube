__int64 __fastcall dsi_ctrl_set_roi(__int64 a1, unsigned __int16 *a2, _BYTE *a3)
{
  __int64 v6; // x8
  const char *v8; // x3

  if ( a1 && a2 && a3 )
  {
    mutex_lock(a1 + 32);
    if ( *(unsigned __int16 *)(a1 + 2760) == *a2
      && *(unsigned __int16 *)(a1 + 2762) == a2[1]
      && *(unsigned __int16 *)(a1 + 2764) == a2[2]
      && *(unsigned __int16 *)(a1 + 2766) == a2[3]
      && *(_BYTE *)(a1 + 2894) != 1 )
    {
      *a3 = 0;
    }
    else
    {
      *a3 = 1;
      v6 = *(_QWORD *)a2;
      *(_BYTE *)(a1 + 2894) = 0;
      *(_QWORD *)(a1 + 2760) = v6;
    }
    mutex_unlock(a1 + 32);
    return 0;
  }
  else
  {
    if ( a1 )
      v8 = *(const char **)(a1 + 16);
    else
      v8 = "inv";
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Invalid params\n", v8);
    return 4294967274LL;
  }
}
