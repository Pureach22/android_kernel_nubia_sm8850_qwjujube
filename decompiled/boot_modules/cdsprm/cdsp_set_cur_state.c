__int64 __fastcall cdsp_set_cur_state(__int64 a1, __int64 a2)
{
  int v2; // w19
  __int64 v3; // x0
  __int64 v5; // [xsp+8h] [xbp-18h] BYREF
  int v6; // [xsp+10h] [xbp-10h]
  __int64 v7; // [xsp+18h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( dword_A470 != a2 )
  {
    v2 = a2;
    v6 = 0;
    v5 = 0;
    mutex_lock(&unk_A440);
    if ( qword_A350 )
    {
      if ( gcdsprm[0] )
      {
        v3 = *(_QWORD *)(qword_A350 + 968);
        LODWORD(v5) = 10;
        HIWORD(v5) = v2;
        WORD2(v5) = dword_A474;
        v6 = 12;
        if ( !(unsigned int)rpmsg_send(v3, &v5, 12) )
          dword_A470 = v2;
      }
    }
    mutex_unlock(&unk_A440);
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
