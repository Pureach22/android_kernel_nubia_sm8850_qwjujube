__int64 __fastcall msm_vidc_set_crc(__int64 a1)
{
  unsigned int v2; // w20
  int v3; // w8
  _QWORD *v4; // x10

  if ( (*(_BYTE *)(a1 + 6444) & 1) != 0 || (*(_BYTE *)(a1 + 6448) & 8) != 0 )
  {
    mutex_lock(a1 + 3856);
    if ( (is_core_state(a1, 2) & 1) != 0 )
    {
      v3 = -1;
      v4 = (_QWORD *)(a1 + 3528);
      do
      {
        v4 = (_QWORD *)*v4;
        ++v3;
      }
      while ( v4 != (_QWORD *)(a1 + 3528) );
      if ( v3 <= 1 )
      {
        v2 = venus_hfi_set_crc(a1);
        if ( v2 && (msm_vidc_debug & 1) != 0 )
          printk(&unk_85B21, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_set_crc");
      }
      else
      {
        v2 = 0;
      }
    }
    else
    {
      v2 = -22;
    }
    mutex_unlock(a1 + 3856);
  }
  else
  {
    return 0;
  }
  return v2;
}
