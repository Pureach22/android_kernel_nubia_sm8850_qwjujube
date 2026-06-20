__int64 __fastcall dsi_panel_get_cmd_pkt_count(__int64 a1, unsigned int a2, _DWORD *a3)
{
  int v3; // w8
  unsigned int v4; // w9
  bool v5; // cf

  if ( a2 < 7 )
  {
    v3 = 0;
LABEL_8:
    *a3 = v3;
    return 0;
  }
  else
  {
    v3 = 0;
    while ( 1 )
    {
      v4 = __rev16(*(unsigned __int16 *)(a1 + 5)) + 7;
      v5 = a2 >= v4;
      a2 -= v4;
      if ( !v5 )
        break;
      a1 += v4;
      ++v3;
      if ( a2 <= 6 )
        goto LABEL_8;
    }
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: format error\n");
    return 4294967274LL;
  }
}
