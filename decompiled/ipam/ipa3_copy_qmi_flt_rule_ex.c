__int64 __fastcall ipa3_copy_qmi_flt_rule_ex(__int64 result, __int64 a2)
{
  int v2; // w22
  int v3; // w8
  int v4; // w8
  int v5; // w8
  int v6; // w8
  __int64 v7; // x10
  __int64 v8; // x10
  __int64 v9; // x10
  __int64 v10; // x10

  *(_DWORD *)result = *(_DWORD *)a2;
  *(_DWORD *)(result + 188) = *(_DWORD *)(a2 + 188);
  if ( *(_BYTE *)(a2 + 192) == 1 )
    *(_DWORD *)(result + 192) = *(_DWORD *)(a2 + 196);
  if ( *(_BYTE *)(a2 + 200) == 1 )
    *(_BYTE *)(result + 196) = *(_DWORD *)(a2 + 204);
  *(_DWORD *)(result + 208) = *(_DWORD *)(a2 + 208);
  *(_BYTE *)(result + 212) = *(_BYTE *)(a2 + 212);
  *(_WORD *)(result + 4) = *(_WORD *)(a2 + 4);
  *(_BYTE *)(result + 6) = *(_BYTE *)(a2 + 6);
  *(_BYTE *)(result + 7) = *(_BYTE *)(a2 + 7);
  *(_BYTE *)(result + 8) = *(_BYTE *)(a2 + 8);
  *(_BYTE *)(result + 9) = *(_BYTE *)(a2 + 9);
  v3 = *(unsigned __int8 *)(a2 + 10);
  *(_BYTE *)(result + 10) = v3;
  if ( v3 )
  {
    *(_BYTE *)(result + 12) = *(_BYTE *)(a2 + 12);
    *(_WORD *)(result + 14) = *(_WORD *)(a2 + 14);
    *(_WORD *)(result + 16) = *(_WORD *)(a2 + 16);
    if ( v3 != 1 )
    {
      *(_BYTE *)(result + 18) = *(_BYTE *)(a2 + 18);
      *(_WORD *)(result + 20) = *(_WORD *)(a2 + 20);
      *(_WORD *)(result + 22) = *(_WORD *)(a2 + 22);
      if ( v3 != 2 )
      {
        *(_BYTE *)(result + 24) = *(_BYTE *)(a2 + 24);
        *(_WORD *)(result + 26) = *(_WORD *)(a2 + 26);
        *(_WORD *)(result + 28) = *(_WORD *)(a2 + 28);
        if ( v3 != 3 )
          goto LABEL_19;
      }
    }
  }
  v4 = *(unsigned __int8 *)(a2 + 24);
  *(_BYTE *)(result + 24) = v4;
  if ( v4 )
  {
    *(_BYTE *)(result + 28) = *(_BYTE *)(a2 + 28);
    *(_DWORD *)(result + 32) = *(_DWORD *)(a2 + 32);
    *(_DWORD *)(result + 36) = *(_DWORD *)(a2 + 36);
    if ( v4 != 1 )
    {
      *(_BYTE *)(result + 40) = *(_BYTE *)(a2 + 40);
      *(_DWORD *)(result + 44) = *(_DWORD *)(a2 + 44);
      *(_DWORD *)(result + 48) = *(_DWORD *)(a2 + 48);
      if ( v4 != 2 )
        goto LABEL_19;
    }
  }
  *(_BYTE *)(result + 52) = *(_BYTE *)(a2 + 52);
  *(_BYTE *)(result + 53) = *(_BYTE *)(a2 + 53);
  *(_BYTE *)(result + 54) = *(_BYTE *)(a2 + 54);
  *(_DWORD *)(result + 56) = *(_DWORD *)(a2 + 56);
  *(_BYTE *)(result + 60) = *(_BYTE *)(a2 + 60);
  *(_BYTE *)(result + 62) = *(_BYTE *)(a2 + 62);
  *(_WORD *)(result + 64) = *(_WORD *)(a2 + 64);
  *(_BYTE *)(result + 66) = *(_BYTE *)(a2 + 66);
  *(_BYTE *)(result + 68) = *(_BYTE *)(a2 + 68);
  *(_DWORD *)(result + 72) = *(_DWORD *)(a2 + 72);
  v5 = *(unsigned __int8 *)(a2 + 76);
  *(_BYTE *)(result + 76) = v5;
  if ( v5 )
  {
    *(_BYTE *)(result + 80) = *(_BYTE *)(a2 + 80);
    *(_DWORD *)(result + 84) = *(_DWORD *)(a2 + 84);
    *(_DWORD *)(result + 88) = *(_DWORD *)(a2 + 88);
    if ( v5 != 1 )
    {
      *(_BYTE *)(result + 92) = *(_BYTE *)(a2 + 92);
      *(_DWORD *)(result + 96) = *(_DWORD *)(a2 + 96);
      *(_DWORD *)(result + 100) = *(_DWORD *)(a2 + 100);
      if ( v5 != 2 )
        goto LABEL_19;
    }
  }
  v6 = *(unsigned __int8 *)(a2 + 104);
  *(_BYTE *)(result + 104) = v6;
  if ( !v6 )
    goto LABEL_18;
  *(_BYTE *)(result + 105) = *(_BYTE *)(a2 + 105);
  v7 = *(_QWORD *)(a2 + 106);
  *(_QWORD *)(result + 114) = *(_QWORD *)(a2 + 114);
  *(_QWORD *)(result + 106) = v7;
  v8 = *(_QWORD *)(a2 + 122);
  *(_QWORD *)(result + 130) = *(_QWORD *)(a2 + 130);
  *(_QWORD *)(result + 122) = v8;
  if ( v6 == 1
    || (*(_BYTE *)(result + 138) = *(_BYTE *)(a2 + 138),
        v9 = *(_QWORD *)(a2 + 139),
        *(_QWORD *)(result + 147) = *(_QWORD *)(a2 + 147),
        *(_QWORD *)(result + 139) = v9,
        v10 = *(_QWORD *)(a2 + 155),
        *(_QWORD *)(result + 163) = *(_QWORD *)(a2 + 163),
        *(_QWORD *)(result + 155) = v10,
        v6 == 2) )
  {
LABEL_18:
    *(_BYTE *)(result + 171) = *(_BYTE *)(a2 + 171);
    *(_BYTE *)(result + 172) = *(_BYTE *)(a2 + 172);
    *(_DWORD *)(result + 176) = *(_DWORD *)(a2 + 176);
    *(_DWORD *)(result + 180) = *(_DWORD *)(a2 + 180);
    *(_BYTE *)(result + 184) = *(_BYTE *)(a2 + 184);
  }
  else
  {
LABEL_19:
    __break(0x5512u);
    if ( !v2 )
      JUMPOUT(0x1A7584);
    return ipa3_wwan_set_modem_state();
  }
  return result;
}
