__int64 __fastcall sde_encoder_dce_disable(__int64 result)
{
  int v1; // w20
  __int64 v2; // x19
  __int64 v3; // x1
  __int64 v4; // x2
  __int64 v5; // x3
  __int64 v6; // x4
  __int64 v7; // x5
  __int64 v8; // x6
  __int64 v9; // x7
  __int64 v10; // x8
  unsigned int v11; // w20
  __int64 v12; // x21
  __int64 v13; // x8
  const char *v14; // x1
  unsigned int v15; // w22
  __int64 v16; // x23
  __int64 v17; // x25
  int v18; // w8
  __int64 v19; // x8
  __int64 v20; // x19
  __int64 v21; // x8
  __int64 (__fastcall *v22)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64); // x8
  __int64 v23; // x8
  __int64 (__fastcall *v24)(_QWORD); // x9
  _DWORD *v25; // x8
  _DWORD *v26; // x8
  __int64 v27; // x0
  unsigned int disp_op; // w0
  __int64 v29; // x8
  unsigned int v30; // w21
  __int64 v31; // x20
  int v32; // w22
  __int64 v33; // x23
  int v34; // w8
  __int64 v35; // x24
  int v36; // w8
  __int64 v37; // x23
  int v38; // w8
  __int64 v39; // x23
  int v40; // w8
  __int64 v41; // [xsp+0h] [xbp-70h] BYREF
  __int64 v42; // [xsp+8h] [xbp-68h]
  __int64 v43; // [xsp+10h] [xbp-60h]
  __int64 v44; // [xsp+18h] [xbp-58h]
  __int64 v45; // [xsp+20h] [xbp-50h]
  __int64 v46; // [xsp+28h] [xbp-48h]
  __int64 v47; // [xsp+30h] [xbp-40h]
  __int64 v48; // [xsp+38h] [xbp-38h]
  __int64 v49; // [xsp+40h] [xbp-30h]
  __int64 v50; // [xsp+48h] [xbp-28h]
  __int64 v51; // [xsp+50h] [xbp-20h]
  __int64 v52; // [xsp+58h] [xbp-18h]
  __int64 v53; // [xsp+60h] [xbp-10h]
  __int64 v54; // [xsp+68h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !result )
    goto LABEL_42;
  v1 = *(_DWORD *)(result + 4004);
  v2 = result;
  if ( v1 != 1 )
  {
    result = sde_encoder_needs_dsc_disable(result);
    if ( (result & 1) == 0 )
    {
      if ( v1 != 2 )
        goto LABEL_42;
      v13 = *(_QWORD *)(v2 + 200);
      if ( v13 && *(_QWORD *)(v13 + 8) )
      {
        disp_op = sde_encoder_get_disp_op(v2);
        v29 = *(_QWORD *)(v2 + 328);
        v30 = disp_op;
        if ( v29 )
          v31 = *(_QWORD *)(v29 + 416);
        else
          v31 = 0;
        v52 = 0;
        v53 = 0;
        v50 = 0;
        v51 = 0;
        v32 = 1;
        v48 = 0;
        v49 = 0;
        v46 = 0;
        v47 = 0;
        v44 = 0;
        v45 = 0;
        v42 = 0;
        v43 = 0;
        v41 = 0;
        sde_encoder_check_curr_mode(v2, 1);
        v33 = *(_QWORD *)(v2 + 400);
        printk(&unk_268F9B, "_dce_vdc_pipe_cfg");
        if ( v33 )
        {
          v34 = *(_DWORD *)(v33 + 32);
          LODWORD(v52) = 1;
          HIDWORD(v52) = v34;
          *(_DWORD *)(v2 + 480) = v34;
        }
        else
        {
          v32 = 0;
        }
        v35 = *(_QWORD *)(v2 + 408);
        printk(&unk_268F9B, "_dce_vdc_pipe_cfg");
        if ( v35 )
        {
          v36 = *(_DWORD *)(v35 + 32);
          LODWORD(v52) = ++v32;
          *(_DWORD *)(v2 + 484) = v36;
          if ( v33 )
            goto LABEL_62;
          HIDWORD(v52) = v36;
        }
        v37 = *(_QWORD *)(v2 + 416);
        printk(&unk_268F9B, "_dce_vdc_pipe_cfg");
        if ( v37 )
        {
          v38 = *(_DWORD *)(v37 + 32);
          LODWORD(v52) = v32 + 1;
          *(_DWORD *)(v2 + 488) = v38;
          if ( v32 )
            goto LABEL_62;
          v32 = 1;
          HIDWORD(v52) = v38;
        }
        v39 = *(_QWORD *)(v2 + 424);
        result = printk(&unk_268F9B, "_dce_vdc_pipe_cfg");
        if ( v39 )
        {
          v40 = *(_DWORD *)(v39 + 32);
          LODWORD(v52) = v32 + 1;
          *(_DWORD *)(v2 + 492) = v40;
          if ( v32 )
            goto LABEL_62;
          HIDWORD(v52) = v40;
        }
        if ( !v31 )
          goto LABEL_42;
        if ( v30 <= 2 )
        {
          v26 = *(_DWORD **)(v31 + 8LL * v30 + 856);
          if ( !v26 )
            goto LABEL_42;
          v27 = v31;
LABEL_37:
          if ( *(v26 - 1) != -1511553041 )
            __break(0x8228u);
          result = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))v26)(v27, &v41, 0);
          goto LABEL_42;
        }
LABEL_62:
        __break(0x5512u);
      }
      v14 = "_dce_vdc_disable";
LABEL_41:
      result = printk(&unk_227447, v14);
      goto LABEL_42;
    }
  }
  if ( !*(_QWORD *)(v2 + 200) )
  {
    v14 = "_dce_dsc_disable";
    goto LABEL_41;
  }
  result = sde_encoder_get_disp_op(v2);
  if ( *(_QWORD *)(*(_QWORD *)(v2 + 200) + 8LL) )
  {
    v10 = *(_QWORD *)(v2 + 328);
    v11 = result;
    v12 = v10 ? *(_QWORD *)(v10 + 416) : 0LL;
    v15 = 0;
    v16 = 0;
    v17 = v2 + 464;
    v52 = 0;
    v53 = 0;
    v50 = 0;
    v51 = 0;
    v48 = 0;
    v49 = 0;
    v46 = 0;
    v47 = 0;
    v44 = 0;
    v45 = 0;
    v42 = 0;
    v43 = 0;
    v41 = 0;
    do
    {
      v19 = v17 + 8 * v16;
      result = *(_QWORD *)(v19 - 32);
      v20 = *(_QWORD *)(v19 - 96);
      if ( result )
      {
        v21 = *(unsigned int *)(result + 28);
        if ( (unsigned int)v21 >= 3 )
          goto LABEL_62;
        v22 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))(result + 8 * v21 + 304);
        if ( v22 )
        {
          if ( *((_DWORD *)v22 - 1) != 1021724354 )
            __break(0x8228u);
          result = v22(result, v3, v4, v5, v6, v7, v8, v9, v41, v42, v43, v44, v45, v46);
        }
      }
      if ( v20 )
      {
        v23 = *(unsigned int *)(v20 + 28);
        if ( (unsigned int)v23 > 2 )
          goto LABEL_62;
        v24 = *(__int64 (__fastcall **)(_QWORD))(v20 + 8 * v23 + 48);
        if ( v24 )
        {
          if ( *((_DWORD *)v24 - 1) != -1883292818 )
            __break(0x8229u);
          result = v24(v20);
          v23 = *(unsigned int *)(v20 + 28);
          if ( (unsigned int)v23 > 2 )
            goto LABEL_62;
        }
        v25 = *(_DWORD **)(v20 + 8 * v23 + 120);
        if ( v25 )
        {
          if ( *(v25 - 1) != 46373723 )
            __break(0x8228u);
          result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v25)(v20, 0, 14);
        }
        v18 = *(_DWORD *)(v20 + 32);
        *(_DWORD *)(v17 + 4 * v16) = v18;
        HIDWORD(v49) = v15 + 1;
        if ( v15 > 3 )
          goto LABEL_62;
        *((_DWORD *)&v50 + v15++) = v18;
      }
      ++v16;
    }
    while ( v16 != 4 );
    if ( v12 )
    {
      if ( v11 <= 2 )
      {
        v26 = *(_DWORD **)(v12 + 8LL * v11 + 856);
        if ( !v26 )
          goto LABEL_42;
        v27 = v12;
        goto LABEL_37;
      }
      goto LABEL_62;
    }
  }
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return result;
}
