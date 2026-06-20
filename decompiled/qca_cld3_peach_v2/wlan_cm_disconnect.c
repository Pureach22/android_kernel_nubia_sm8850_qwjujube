__int64 __fastcall wlan_cm_disconnect(__int64 a1, int a2, int a3, int *a4)
{
  unsigned __int8 v4; // w8
  __int16 v5; // w9
  __int64 result; // x0
  __int64 v7; // [xsp+0h] [xbp-20h] BYREF
  int v8; // [xsp+8h] [xbp-18h]
  int v9; // [xsp+Ch] [xbp-14h]
  int v10; // [xsp+10h] [xbp-10h]
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_BYTE *)(a1 + 168);
  v9 = 0;
  v10 = 0;
  LODWORD(v7) = v4;
  HIDWORD(v7) = a2;
  v8 = a3;
  if ( a4 )
  {
    v5 = *((_WORD *)a4 + 2);
    v9 = *a4;
    LOWORD(v10) = v5;
  }
  result = cm_disconnect_start_req(a1, &v7);
  _ReadStatusReg(SP_EL0);
  return result;
}
