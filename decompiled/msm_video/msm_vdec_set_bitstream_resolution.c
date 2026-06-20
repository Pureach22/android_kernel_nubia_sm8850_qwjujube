__int64 __fastcall msm_vdec_set_bitstream_resolution(__int64 result, unsigned int a2)
{
  __int64 v2; // x19
  __int64 v3; // x4
  int v4; // w21
  unsigned int hfi_port; // w0
  unsigned int v6; // w22
  __int64 v7; // x2
  unsigned int v8; // w19
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v2 = result;
  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned int *)(result + 392);
  v4 = *(_DWORD *)(result + 396) | ((_DWORD)v3 << 16);
  v9 = v4;
  if ( result && (msm_vidc_debug & 2) != 0 )
  {
    v6 = a2;
    LODWORD(result) = printk(&unk_802B8, "high", result + 340, "msm_vdec_set_bitstream_resolution", v3);
    a2 = v6;
    if ( v6 <= 4 )
      goto LABEL_4;
LABEL_9:
    __break(0x5512u);
LABEL_10:
    v7 = v2 + 340;
    v8 = result;
    printk(&unk_8E17E, "err ", v7, "msm_vdec_set_bitstream_resolution", v3);
    result = v8;
    goto LABEL_7;
  }
  if ( a2 > 4 )
    goto LABEL_9;
LABEL_4:
  *(_DWORD *)(v2 + 56LL * a2 + 3272) = v4;
  hfi_port = get_hfi_port(v2, a2);
  result = venus_hfi_session_property(v2, 50331907, 0, hfi_port, 1, &v9, 4);
  if ( v2 && (_DWORD)result && (msm_vidc_debug & 1) != 0 )
    goto LABEL_10;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
