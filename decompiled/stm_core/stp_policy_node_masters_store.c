__int64 __fastcall stp_policy_node_masters_store(__int64 a1, char *s, __int64 a3)
{
  __int64 v5; // x10
  int v6; // w9
  __int64 v7; // x10
  __int64 v9; // [xsp+0h] [xbp-10h] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  if ( sscanf(s, "%u %u", (char *)&v9 + 4, &v9) == 2 )
  {
    mutex_lock(&unk_440);
    v5 = *(_QWORD *)(*(_QWORD *)(a1 + 136) + 136LL);
    if ( v5 )
    {
      v6 = v9;
      if ( HIDWORD(v9) <= (unsigned int)v9
        && (v7 = *(_QWORD *)(v5 + 984), HIDWORD(v9) >= *(_DWORD *)(v7 + 16))
        && (unsigned int)v9 <= *(_DWORD *)(v7 + 20) )
      {
        *(_DWORD *)(a1 + 144) = HIDWORD(v9);
        *(_DWORD *)(a1 + 148) = v6;
      }
      else
      {
        a3 = -34;
      }
    }
    else
    {
      a3 = -19;
    }
    mutex_unlock(&unk_440);
  }
  else
  {
    a3 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return a3;
}
