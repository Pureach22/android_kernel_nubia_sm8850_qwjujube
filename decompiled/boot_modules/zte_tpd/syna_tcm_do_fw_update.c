__int64 __fastcall syna_tcm_do_fw_update(__int64 a1, __int64 a2, __int64 a3, unsigned int a4, char a5)
{
  void *v5; // x0
  unsigned int v7; // w22
  __int64 v9; // x24
  unsigned int v10; // w21
  unsigned int v11; // w20
  unsigned int v12; // w19
  __int64 result; // x0
  __int64 v14; // x2
  unsigned int v15; // w0
  __int64 v16; // x2
  __int64 v17; // x2
  __int64 v18; // x0
  unsigned int v19; // w19
  void *v20; // x0
  int v21; // w26
  __int64 v22; // x25
  __int64 v23; // x9
  unsigned int v24; // w23
  int v25; // w22
  __int64 v26; // x8
  unsigned __int8 *v27; // x8
  void *v28; // x22
  unsigned int v29; // w25
  void *v30; // x0
  __int64 v31; // x2
  _QWORD s[99]; // [xsp+8h] [xbp-318h] BYREF

  s[98] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    if ( !a2 || !(_DWORD)a3 )
    {
      v5 = &unk_37F8D;
      goto LABEL_8;
    }
    v7 = a3;
    if ( a4 )
    {
      v12 = HIWORD(a4);
      v11 = *(_DWORD *)(a1 + 488);
      v9 = a1;
      v10 = (unsigned __int16)a4;
    }
    else
    {
      v9 = a1;
      v10 = 0;
      v11 = 0;
      v12 = 0;
    }
    memset(s, 0, 0x310u);
    printk(&unk_34450, "syna_tcm_do_fw_update", v14);
    v15 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD *))syna_tcm_parse_fw_image)(a2, v7, s);
    if ( (v15 & 0x80000000) != 0 )
    {
      v19 = v15;
      printk(&unk_331C0, "syna_tcm_do_fw_update", v16);
      result = v19;
      goto LABEL_14;
    }
    if ( (a5 & 1) != 0 )
    {
      v17 = 9;
      v18 = v9;
LABEL_13:
      result = syna_tcm_do_fw_update_ex(v18, s, v17, v12, v10, v11, 1u);
      goto LABEL_14;
    }
    if ( LODWORD(s[16]) < 0x22 )
    {
      v20 = &unk_3858A;
LABEL_18:
      printk(v20, "syna_tcm_compare_image_id_info", v16);
      result = 0;
      goto LABEL_14;
    }
    v21 = *(unsigned __int8 *)(v9 + 8);
    v22 = s[15];
    v23 = 14;
    v24 = *(_DWORD *)(v9 + 12);
    if ( v21 == 2 )
      v23 = 16;
    v25 = *(_DWORD *)(s[15] + v23);
    printk(&unk_3BB70, "syna_tcm_compare_image_id_info", v24);
    if ( v25 == v24 )
    {
      v26 = 18;
      if ( v21 == 2 )
        v26 = 20;
      v27 = (unsigned __int8 *)(v22 + v26);
      if ( *v27 == *(unsigned __int8 *)(v9 + 192)
        && v27[1] == *(unsigned __int8 *)(v9 + 193)
        && v27[2] == *(unsigned __int8 *)(v9 + 194)
        && v27[3] == *(unsigned __int8 *)(v9 + 195)
        && v27[4] == *(unsigned __int8 *)(v9 + 196)
        && v27[5] == *(unsigned __int8 *)(v9 + 197)
        && v27[6] == *(unsigned __int8 *)(v9 + 198)
        && v27[7] == *(unsigned __int8 *)(v9 + 199)
        && v27[8] == *(unsigned __int8 *)(v9 + 200)
        && v27[9] == *(unsigned __int8 *)(v9 + 201)
        && v27[10] == *(unsigned __int8 *)(v9 + 202)
        && v27[11] == *(unsigned __int8 *)(v9 + 203)
        && v27[12] == *(unsigned __int8 *)(v9 + 204)
        && v27[13] == *(unsigned __int8 *)(v9 + 205)
        && v27[14] == *(unsigned __int8 *)(v9 + 206)
        && v27[15] == *(unsigned __int8 *)(v9 + 207) )
      {
        v20 = &unk_321A7;
        goto LABEL_18;
      }
      v28 = &unk_3688D;
      v29 = 1;
      v30 = &unk_385C2;
    }
    else
    {
      v28 = &unk_3C83E;
      v29 = 9;
      v30 = &unk_3BBAA;
    }
    printk(v30, "syna_tcm_compare_image_id_info", v16);
    printk(v28, "syna_tcm_compare_image_id_info", v31);
    v18 = v9;
    v17 = v29;
    goto LABEL_13;
  }
  v5 = &unk_3365A;
LABEL_8:
  printk(v5, "syna_tcm_do_fw_update", a3);
  result = 4294967055LL;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
