__int64 __fastcall dot11f_pack_ie_wsc_assoc_req(__int64 a1, _BYTE *a2, _BYTE *a3, unsigned int a4, int *a5)
{
  int v5; // w8
  __int64 result; // x0
  unsigned __int64 v12; // x26
  int v13; // w27
  int v14; // w28
  unsigned int v15; // w3
  int v16; // w8
  __int64 v17; // x8
  bool v18; // zf
  _QWORD v19[2]; // [xsp+0h] [xbp-10h] BYREF

  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = (unsigned __int8)*a2;
  v19[0] = 0;
  if ( !v5 )
    goto LABEL_14;
  result = get_packed_size_tlv_core((__int64)a2, (int *)v19, (unsigned int *)&TLVS_WscAssocReq);
  if ( (_DWORD)result )
    goto LABEL_15;
  result = 268435461;
  if ( LODWORD(v19[0]) > a4 )
    goto LABEL_15;
  if ( !*a2 )
  {
LABEL_14:
    result = 0;
    goto LABEL_15;
  }
  v12 = 0;
  do
  {
    v13 = *a5;
    *a3 = -35;
    *a5 += 2;
    a3[2] = 0;
    ++*a5;
    a3[3] = 80;
    ++*a5;
    a3[4] = -14;
    ++*a5;
    a3[5] = 4;
    v14 = *a5 + 1;
    *a5 = v14;
    if ( v12 >= 5 )
      __break(0x5512u);
    if ( a4 - 6 >= 0xFB )
      v15 = 251;
    else
      v15 = a4 - 6;
    result = pack_tlv_core(a1, (__int64)a2, a3 + 6, v15, a5, (__int64)&TLVS_WscAssocReq + 40 * v12, (_DWORD *)v19 + 1);
    v16 = *a5;
    a3[1] = *a5 - v13 - 2;
    if ( (_DWORD)result != 268435461 )
      break;
    v17 = (unsigned int)(v16 - v14);
    a3 += v17 + 6;
    a4 = a4 - 6 - v17;
    v18 = v12 == HIDWORD(v19[0]);
    v12 = HIDWORD(v19[0]);
  }
  while ( !v18 );
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
