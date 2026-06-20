__int64 __fastcall data_sink_store(__int64 a1, int a2, char *s, int a4)
{
  __int64 v5; // x19
  __int64 v7; // x22
  __int64 result; // x0
  int v9; // w9
  __int64 v10; // [xsp+8h] [xbp-18h] BYREF
  __int16 v11; // [xsp+10h] [xbp-10h]
  __int64 v12; // [xsp+18h] [xbp-8h]

  LODWORD(v5) = a4;
  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 152);
  v11 = 0;
  v10 = 0;
  if ( strlen(s) <= 9 && sscanf(s, "%8s", &v10) == 1 )
  {
    mutex_lock(v7 + 24);
    if ( *(_DWORD *)(v7 + 328) <= (unsigned int)*(unsigned __int8 *)(v7 + 332) )
    {
      dev_err(a1, "Select link list to program using curr_list\n");
      v5 = -22;
      goto LABEL_12;
    }
    if ( (*(_BYTE *)(*(_QWORD *)(v7 + 120) + *(unsigned __int8 *)(v7 + 332)) & 1) != 0 )
    {
      v5 = -16;
LABEL_12:
      mutex_unlock(v7 + 24);
      result = v5;
      goto LABEL_13;
    }
    v9 = v10 ^ 0x6D617273 | BYTE4(v10);
    if ( v9 )
    {
      if ( (_DWORD)v10 != 6452321 )
      {
        v5 = -22;
        goto LABEL_12;
      }
      v9 = 1;
    }
    v5 = (int)v5;
    *(_DWORD *)(*(_QWORD *)(v7 + 88) + 4LL * *(unsigned __int8 *)(v7 + 332)) = v9;
    goto LABEL_12;
  }
  result = -22;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
