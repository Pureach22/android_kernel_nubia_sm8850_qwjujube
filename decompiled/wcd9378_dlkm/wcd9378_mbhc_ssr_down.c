__int64 __fastcall wcd9378_mbhc_ssr_down(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 v5; // x20

  if ( result && a2 )
  {
    v2 = result;
    v3 = *(_QWORD *)(a2 + 24);
    v4 = *(_QWORD *)(v3 + 152);
    if ( v4 )
    {
      v5 = *(_QWORD *)(v4 + 336);
      if ( v5 )
      {
        wcd_mbhc_stop(*(_QWORD *)(v4 + 336));
        if ( *(_BYTE *)(v5 + 207) == 1 )
        {
          wcd9378_micbias_control(a2, 2u, 3, 0);
          *(_BYTE *)(v5 + 207) = 0;
        }
      }
      else
      {
        dev_err(v3, "%s: mbhc not initialized!\n", "wcd9378_mbhc_hs_detect_exit");
      }
    }
    else
    {
      printk(&unk_131C3, "wcd9378_mbhc_hs_detect_exit");
    }
    return wcd_mbhc_deinit(v2);
  }
  return result;
}
