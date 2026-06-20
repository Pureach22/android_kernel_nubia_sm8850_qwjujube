__int64 __fastcall msm_venc_g_param(__int64 a1, unsigned int *a2)
{
  unsigned int v2; // w8
  __int64 v3; // x9
  unsigned __int64 v4; // x9
  __int64 v7; // x0

  v2 = *a2;
  a2[3] = 1;
  if ( v2 == 10 )
    v3 = 19640;
  else
    v3 = 19472;
  v4 = *(_QWORD *)(a1 + v3);
  a2[1] = 4096;
  a2[4] = v4 >> 16;
  if ( !a1 || (msm_vidc_debug & 2) == 0 )
    return 0;
  v7 = v4l2_type_name(v2);
  printk(&unk_83471, "high", a1 + 340, "msm_venc_g_param", v7);
  return 0;
}
