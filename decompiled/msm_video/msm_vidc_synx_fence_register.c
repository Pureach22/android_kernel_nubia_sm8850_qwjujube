unsigned __int64 __fastcall msm_vidc_synx_fence_register(__int64 a1)
{
  unsigned __int64 result; // x0
  unsigned __int64 v3; // x20
  int v4; // w8
  int v5; // w9
  __int64 v6; // x8
  int v7; // w10
  unsigned int v8; // w20
  __int64 v9; // [xsp+0h] [xbp-90h] BYREF
  __int64 v10; // [xsp+8h] [xbp-88h]
  __int64 v11; // [xsp+10h] [xbp-80h]
  __int64 v12; // [xsp+18h] [xbp-78h]
  __int64 v13; // [xsp+20h] [xbp-70h]
  __int64 v14; // [xsp+28h] [xbp-68h]
  _QWORD v15[2]; // [xsp+30h] [xbp-60h] BYREF
  int v16; // [xsp+40h] [xbp-50h]
  int v17; // [xsp+44h] [xbp-4Ch]
  _QWORD v18[9]; // [xsp+48h] [xbp-48h] BYREF

  v18[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_QWORD *)(a1 + 4624) )
    goto LABEL_6;
  memset((char *)&v18[6] + 1, 0, 15);
  strcpy((char *)v18, "video synx fence");
  v15[0] = v18;
  v15[1] = &v9;
  memset((char *)&v18[2] + 1, 0, 32);
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v16 = 1152;
  v17 = 1;
  result = synx_initialize(v15);
  v3 = result;
  if ( result && result < 0xFFFFFFFFFFFFF001LL )
  {
    v4 = v16;
    v5 = v17;
    result = 0;
    *(_QWORD *)(a1 + 6624) = v3;
    *(_DWORD *)(a1 + 6752) = 0;
    *(_DWORD *)(a1 + 6616) = v4;
    v6 = v10;
    v7 = v11;
    *(_DWORD *)(a1 + 6632) = v5;
    *(_QWORD *)(a1 + 6696) = v9;
    *(_QWORD *)(a1 + 6744) = v6;
    LOBYTE(v5) = msm_vidc_debug;
    *(_DWORD *)(a1 + 6664) = v7;
    *(_QWORD *)(a1 + 6656) = 0x200000006LL;
    if ( (v5 & 2) != 0 )
    {
      printk(&unk_90DCF, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_synx_fence_register");
LABEL_6:
      result = 0;
    }
  }
  else if ( (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_932F7, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_synx_fence_register");
    if ( v3 )
      result = (unsigned int)v3;
    else
      result = 4294967274LL;
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v8 = result;
      printk(&unk_94CDA, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_synx_fence_register");
      result = v8;
    }
    *(_QWORD *)(a1 + 4624) = 0;
  }
  else
  {
    *(_QWORD *)(a1 + 4624) = 0;
    if ( result )
      result = (unsigned int)result;
    else
      result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
