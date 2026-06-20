__int64 __fastcall msm_vidc_synx_fence_create(__int64 a1, __int64 a2, int a3, int a4, __int64 a5)
{
  __int64 v6; // x21
  __int64 result; // x0
  __int64 v8; // x22
  __int64 v9; // x20
  __int64 v10; // x0
  void *v11; // x0
  int v12; // [xsp+4h] [xbp-2Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-28h] BYREF
  unsigned int *v14; // [xsp+10h] [xbp-20h]
  __int64 v15; // [xsp+18h] [xbp-18h]
  __int64 v16; // [xsp+20h] [xbp-10h]
  __int64 v17; // [xsp+28h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 320);
  v12 = 0;
  if ( !*(_QWORD *)(v6 + 6624) )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      goto LABEL_14;
    v11 = &unk_825AA;
    goto LABEL_18;
  }
  result = msm_vidc_get_sw_fence(a1, a2, a3, a4, a5);
  if ( !result )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      goto LABEL_14;
    v11 = &unk_93108;
LABEL_18:
    printk(v11, "err ", a1 + 340, "msm_vidc_synx_fence_create", a5);
LABEL_14:
    result = 0;
    goto LABEL_15;
  }
  if ( *(_DWORD *)(result + 144) != 1 )
  {
    v8 = result;
    v9 = result + 16;
    v15 = result + 184;
    v16 = 0;
    v10 = *(_QWORD *)(v6 + 6624);
    v13 = v9;
    v14 = (unsigned int *)&v12;
    LODWORD(v16) = 4;
    if ( !(unsigned int)synx_create(v10, &v13) )
    {
      *(_QWORD *)(v8 + 160) = *v14;
      *(_QWORD *)(v8 + 176) = *(_QWORD *)(v6 + 6624);
      populate_fence_name(a1, v8, 0);
      result = v8;
      goto LABEL_15;
    }
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_90E12, "err ", a1 + 340, "msm_vidc_synx_fence_create", v9);
    msm_vidc_fence_signal(a1, v8, 1);
    msm_vidc_put_sw_fence(a1, (char *)v8);
    goto LABEL_14;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
