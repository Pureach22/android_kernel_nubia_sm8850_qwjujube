__int64 __fastcall stp_policy_node_channels_store(__int64 a1, char *s, __int64 a3)
{
  __int64 v5; // x10
  __int64 v6; // x21
  int v7; // w9
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
      v6 = -34;
      if ( (v9 & 0x8000000000000000LL) == 0 )
      {
        v7 = v9;
        if ( (v9 & 0x80000000) == 0
          && HIDWORD(v9) <= (unsigned int)v9
          && (unsigned int)v9 < *(_DWORD *)(*(_QWORD *)(v5 + 984) + 24LL) )
        {
          v6 = a3;
          *(_DWORD *)(a1 + 152) = HIDWORD(v9);
          *(_DWORD *)(a1 + 156) = v7;
        }
      }
    }
    else
    {
      v6 = -19;
    }
    mutex_unlock(&unk_440);
  }
  else
  {
    v6 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v6;
}
