__int64 __fastcall msm_vidc_synx_fence_import(__int64 a1, __int64 a2, int a3, int a4, __int64 a5)
{
  __int64 v6; // x21
  __int64 sw_fence; // x0
  __int64 v8; // x20
  __int64 v9; // x9
  __int64 v10; // x0
  void *v11; // x0
  int v13; // [xsp+4h] [xbp-3Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-38h] BYREF
  unsigned int *v15; // [xsp+10h] [xbp-30h]
  __int64 v16; // [xsp+18h] [xbp-28h]
  __int64 v17; // [xsp+20h] [xbp-20h]
  __int64 v18; // [xsp+28h] [xbp-18h]
  __int64 v19; // [xsp+30h] [xbp-10h]
  __int64 v20; // [xsp+38h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 320);
  v13 = 0;
  if ( !*(_QWORD *)(v6 + 6624) )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      goto LABEL_13;
    v11 = &unk_825AA;
LABEL_17:
    printk(v11, "err ", a1 + 340, "msm_vidc_synx_fence_import", a5);
    goto LABEL_13;
  }
  sw_fence = msm_vidc_get_sw_fence(a1, a2, a3, a4, a5);
  if ( !sw_fence )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      goto LABEL_13;
    v11 = &unk_815B8;
    goto LABEL_17;
  }
  v8 = sw_fence;
  v15 = (unsigned int *)&v13;
  v14 = 1;
  v9 = *(_QWORD *)(sw_fence + 264);
  v10 = *(_QWORD *)(v6 + 6624);
  v18 = 0;
  v19 = 0;
  v17 = v9;
  v16 = 8;
  if ( !(unsigned int)synx_import(v10, &v14) )
  {
    *(_QWORD *)(v8 + 160) = *v15;
    *(_QWORD *)(v8 + 176) = *(_QWORD *)(v6 + 6624);
    populate_fence_name(a1, v8, 0);
    goto LABEL_14;
  }
  if ( a1 && (msm_vidc_debug & 1) != 0 )
    printk(&unk_8F334, "err ", a1 + 340, "msm_vidc_synx_fence_import", v8 + 16);
  msm_vidc_put_sw_fence(a1, (char *)v8);
LABEL_13:
  v8 = 0;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v8;
}
