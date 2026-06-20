__int64 __fastcall msm_venc_set_crop_offsets(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  __int64 v3; // x9
  __int64 v4; // x4
  int v5; // w5
  int v6; // w8
  int v7; // w9
  int v8; // w12
  __int64 v9; // x10
  int v10; // w9
  int v11; // w8
  int v12; // w6
  int v13; // w7
  __int64 v14; // x19
  unsigned int hfi_port; // w0
  __int64 v16; // x19
  unsigned int v17; // w20
  _DWORD v18[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 < 2 )
  {
    if ( a2 )
    {
      v3 = *(_QWORD *)(a1 + 23168);
      v4 = *(unsigned int *)(a1 + 1896);
      v5 = *(_DWORD *)(a1 + 1900);
      v6 = *(_DWORD *)(a1 + 1904);
      if ( v3 == 270 || v3 == 90 )
      {
        v7 = *(_DWORD *)(a1 + 1908);
      }
      else
      {
        v7 = *(_DWORD *)(a1 + 1904);
        v6 = *(_DWORD *)(a1 + 1908);
      }
    }
    else
    {
      v4 = *(unsigned int *)(a1 + 1880);
      v5 = *(_DWORD *)(a1 + 1884);
      v7 = *(_DWORD *)(a1 + 1888);
      v6 = *(_DWORD *)(a1 + 1892);
    }
    v8 = *(_DWORD *)(a1 + 312);
    v9 = a1 + 208LL * a2;
    v10 = *(_DWORD *)(v9 + 392) - v7;
    v11 = *(_DWORD *)(v9 + 396) - v6;
    if ( v8 == 8 )
      v12 = 0;
    else
      v12 = v10;
    if ( v8 == 8 )
      v13 = 0;
    else
      v13 = v11;
    v18[0] = v5 | ((_DWORD)v4 << 16);
    v18[1] = v13 | (v12 << 16);
    if ( a1 && (msm_vidc_debug & 2) != 0 )
    {
      v16 = a1;
      v17 = a2;
      printk(&unk_93837, "high", a1 + 340, "msm_venc_set_crop_offsets", v4);
      a2 = v17;
      a1 = v16;
    }
    v14 = a1;
    hfi_port = get_hfi_port(a1, a2);
    result = venus_hfi_session_property(v14, 50331909, 0, hfi_port, 13, v18, 8);
  }
  else if ( a1 && (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_80EB0, "err ", a1 + 340, "msm_venc_set_crop_offsets", a2);
    result = 4294967274LL;
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
