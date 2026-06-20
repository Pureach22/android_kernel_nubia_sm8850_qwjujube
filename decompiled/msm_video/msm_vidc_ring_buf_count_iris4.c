__int64 __fastcall msm_vidc_ring_buf_count_iris4(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x19
  __int64 result; // x0
  __int64 v8; // x8
  _BYTE dest[136]; // [xsp+8h] [xbp-138h] BYREF
  _QWORD v10[4]; // [xsp+90h] [xbp-B0h] BYREF
  _QWORD src[18]; // [xsp+B0h] [xbp-90h] BYREF

  src[17] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 320);
  if ( *(_QWORD *)(v5 + 3904) )
  {
    memset(src, 0, 136);
    memset(v10, 0, sizeof(v10));
    result = msm_vidc_init_codec_input_freq(a1, a2, src);
    if ( !(_DWORD)result )
    {
      memcpy(dest, src, sizeof(dest));
      result = ((__int64 (__fastcall *)(_BYTE *, _QWORD *))msm_vidc_calculate_frequency)(dest, v10);
      if ( !(_DWORD)result )
      {
        if ( (is_vpp_cycles_close_to_freq_corner(v5, LODWORD(v10[0])) & 1) != 0 )
        {
          v8 = a1;
          if ( a1 && (msm_vidc_debug & 2) != 0 )
          {
            printk(&unk_88D47, "high", a1 + 340, "msm_vidc_ring_buf_count_iris4", LODWORD(v10[0]));
            v8 = a1;
          }
          result = 0;
          *(_QWORD *)(v8 + 21488) = 5;
        }
        else
        {
          result = 0;
          *(_QWORD *)(a1 + 21488) = 0;
        }
      }
    }
  }
  else
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_7F6E8, "err ", a1 + 340, "msm_vidc_ring_buf_count_iris4", a5);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
