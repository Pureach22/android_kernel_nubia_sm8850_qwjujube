__int64 __fastcall msm_venc_set_stride_scanline(__int64 result, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // w8
  int v6; // w9
  int v7; // w12
  int v8; // w9
  __int64 v9; // x4
  unsigned int v10; // w5
  int v11; // w9
  int v12; // w9
  int v13; // w10
  int v14; // w9
  unsigned int v15; // w7
  int v16; // w6
  __int64 v17; // x19
  unsigned int hfi_port; // w0
  __int64 v19; // x19
  _DWORD v20[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    if ( result && (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_80EB0, "err ", result + 340, "msm_venc_set_stride_scanline", a2);
      result = 4294967274LL;
    }
    else
    {
      result = 4294967274LL;
    }
    goto LABEL_54;
  }
  v5 = *(_DWORD *)(result + 18128);
  if ( (unsigned int)(v5 - 2) <= 0x3E && ((1LL << ((unsigned __int8)v5 - 2)) & 0x4000000000004005LL) != 0 || v5 == 256 )
  {
    if ( *(_DWORD *)(result + 312) == 8 )
    {
      v6 = *(_DWORD *)(result + 26528);
      v7 = v6 - 1;
      v8 = -v6;
      v9 = (v7 + *(_DWORD *)(result + 392)) & (unsigned int)v8;
      v10 = (*(_DWORD *)(result + 396) + v7) & v8;
      goto LABEL_44;
    }
    if ( v5 == 64 || v5 == 32 )
    {
      v11 = *(_DWORD *)(result + 392);
      if ( v11 )
      {
        v9 = (v11 + 63) & 0x3FFFFFC0;
        v12 = *(_DWORD *)(result + 396);
        if ( !v12 )
          goto LABEL_39;
LABEL_20:
        if ( v5 != 32 )
        {
          v13 = 32;
LABEL_43:
          v10 = (v12 + v13 - 1) & -v13;
          goto LABEL_44;
        }
LABEL_42:
        v13 = 16;
        goto LABEL_43;
      }
      v9 = 0;
      v12 = *(_DWORD *)(result + 396);
      if ( v12 )
        goto LABEL_20;
LABEL_39:
      v10 = 0;
      goto LABEL_44;
    }
    v14 = *(_DWORD *)(result + 392);
    if ( !v14 )
    {
      v9 = 0;
      goto LABEL_33;
    }
    v9 = 0;
    if ( v5 > 15 )
    {
      if ( v5 != 16 && v5 != 256 )
        goto LABEL_33;
    }
    else if ( v5 != 2 && v5 != 4 )
    {
      if ( v5 == 8 )
        v9 = 192 * ((v14 + 191) / 0xC0u);
LABEL_33:
      v12 = *(_DWORD *)(result + 396);
      if ( v12 )
      {
        v10 = 0;
        v13 = 32;
        if ( v5 > 15 )
        {
          if ( v5 == 16 )
            goto LABEL_43;
          if ( v5 != 256 )
            goto LABEL_44;
        }
        else
        {
          if ( v5 == 2 || v5 == 4 )
            goto LABEL_43;
          if ( v5 != 8 )
          {
LABEL_44:
            if ( (unsigned int)v5 <= 0x10 && ((1 << v5) & 0x10014) != 0 )
            {
              v15 = v10 >> 1;
              v16 = v9;
            }
            else if ( v5 == 256 )
            {
              v16 = v9;
              v15 = v10;
            }
            else
            {
              v16 = 0;
              v15 = 0;
            }
            v20[0] = v10 | ((_DWORD)v9 << 16);
            v20[1] = v15 | (v16 << 16);
            if ( result && (msm_vidc_debug & 2) != 0 )
            {
              v19 = result;
              printk(&unk_960DB, "high", result + 340, "msm_venc_set_stride_scanline", v9);
              result = v19;
            }
            v17 = result;
            hfi_port = get_hfi_port(result, 0);
            result = venus_hfi_session_property(v17, 50331908, 0, hfi_port, 13, v20, 8);
            goto LABEL_54;
          }
        }
        goto LABEL_42;
      }
      goto LABEL_39;
    }
    v9 = (v14 + 127) & 0xFFFFFF80;
    goto LABEL_33;
  }
  if ( result )
  {
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_89A2E, "high", result + 340, "msm_venc_set_stride_scanline", a5);
    result = 0;
  }
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return result;
}
