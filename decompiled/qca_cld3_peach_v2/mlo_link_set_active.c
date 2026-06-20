__int64 __fastcall mlo_link_set_active(
        __int64 a1,
        _QWORD *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16)
{
  __int64 v16; // x19
  _DWORD *v17; // x8
  _DWORD *v18; // x9
  _QWORD *v19; // x20
  _QWORD *v20; // x1
  __int64 v21; // x21
  unsigned int v22; // w0
  unsigned int v23; // w19
  void (__fastcall *v24)(__int64, __int64, __int64 *); // x8
  __int64 v25; // x0
  __int64 v26; // x1
  __int64 result; // x0
  const char *v28; // x2
  _QWORD *v29; // x1
  __int64 v30; // [xsp+0h] [xbp-40h] BYREF
  __int64 v31; // [xsp+8h] [xbp-38h]
  __int64 v32; // [xsp+10h] [xbp-30h]
  __int64 v33; // [xsp+18h] [xbp-28h]
  __int64 v34; // [xsp+20h] [xbp-20h]
  __int64 v35; // [xsp+28h] [xbp-18h]
  __int64 v36; // [xsp+30h] [xbp-10h]
  __int64 v37; // [xsp+38h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *(_QWORD *)(a1 + 2128);
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v30 = 0;
  if ( !v16 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: tx_ops is NULL",
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      a15,
      a16,
      "target_if_mlo_get_tx_ops",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37);
    v28 = "%s: tx_ops is null!";
LABEL_14:
    qdf_trace_msg(0x8Fu, 2u, v28, a9, a10, a11, a12, a13, a14, a15, a16, "mlo_link_set_active", v30);
    result = 29;
    goto LABEL_19;
  }
  v17 = *(_DWORD **)(v16 + 2000);
  if ( !v17 )
  {
    v28 = "%s: link_set_active function is null!";
    goto LABEL_14;
  }
  v18 = (_DWORD *)a2[2];
  if ( v18 )
  {
    v19 = a2;
    v20 = a2 + 4;
    v21 = a1;
    if ( *(v18 - 1) != -1051866161 )
      __break(0x8229u);
    v22 = ((__int64 (__fastcall *)(__int64, _QWORD *, __int64, __int64, __int64, __int64, __int64, __int64))v18)(
            a1,
            v20,
            a3,
            a4,
            a5,
            a6,
            a7,
            a8);
    if ( v22 )
    {
      v23 = v22;
      qdf_mem_set(&v30, 0x38u, 0);
      v24 = (void (__fastcall *)(__int64, __int64, __int64 *))v19[1];
      LODWORD(v30) = v23;
      if ( v24 )
      {
        v25 = *v19;
        v26 = v19[3];
        if ( *((_DWORD *)v24 - 1) != 662908326 )
          __break(0x8228u);
        v24(v25, v26, &v30);
      }
      result = v23;
      goto LABEL_19;
    }
    v17 = *(_DWORD **)(v16 + 2000);
    a2 = v19;
    a1 = v21;
  }
  v29 = a2 + 4;
  if ( *(v17 - 1) != -1051866161 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD *))v17)(a1, v29);
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
