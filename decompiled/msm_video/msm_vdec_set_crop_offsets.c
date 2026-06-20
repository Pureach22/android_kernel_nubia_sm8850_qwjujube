__int64 __fastcall msm_vdec_set_crop_offsets(__int64 result, unsigned int a2)
{
  __int64 v2; // x19
  __int64 v3; // x4
  int v4; // w21
  int v5; // w22
  __int64 v6; // x8
  unsigned int hfi_port; // w0
  unsigned int v8; // w23
  __int64 v9; // x2
  unsigned int v10; // w19
  _DWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v2 = result;
  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned int *)(result + 1880);
  v4 = *(_DWORD *)(result + 1884) | ((_DWORD)v3 << 16);
  v5 = (*(_DWORD *)(result + 396) - *(_DWORD *)(result + 1892))
     | ((*(_DWORD *)(result + 392) - *(_DWORD *)(result + 1888)) << 16);
  v11[0] = v4;
  v11[1] = v5;
  if ( result && (msm_vidc_debug & 2) != 0 )
  {
    v8 = a2;
    LODWORD(result) = printk(&unk_93837, "high", result + 340, "msm_vdec_set_crop_offsets", v3);
    a2 = v8;
    if ( v8 <= 4 )
      goto LABEL_4;
LABEL_9:
    __break(0x5512u);
LABEL_10:
    v9 = v2 + 340;
    v10 = result;
    printk(&unk_8E17E, "err ", v9, "msm_vdec_set_crop_offsets", v3);
    result = v10;
    goto LABEL_7;
  }
  if ( a2 > 4 )
    goto LABEL_9;
LABEL_4:
  v6 = v2 + 56LL * a2;
  *(_DWORD *)(v6 + 3276) = v4;
  *(_DWORD *)(v6 + 3280) = v5;
  hfi_port = get_hfi_port(v2, a2);
  result = venus_hfi_session_property(v2, 50331909, 0, hfi_port, 13, v11, 8);
  if ( v2 && (_DWORD)result && (msm_vidc_debug & 1) != 0 )
    goto LABEL_10;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
