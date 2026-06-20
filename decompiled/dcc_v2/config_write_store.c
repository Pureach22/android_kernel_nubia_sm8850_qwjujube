__int64 __fastcall config_write_store(__int64 a1, __int64 a2, const char *a3, __int64 a4)
{
  __int64 v7; // x20
  int v8; // w0
  int v9; // w22
  unsigned int v11; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v12; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v13; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 152);
  v13 = 0;
  v11 = 0;
  v12 = 0;
  mutex_lock(v7 + 24);
  v8 = sscanf(a3, "%x %x %d", &v13, &v12, &v11);
  v9 = -22;
  if ( (unsigned int)(v8 - 4) >= 0xFFFFFFFE && v11 <= 1 )
  {
    if ( *(_DWORD *)(v7 + 328) <= (unsigned int)*(unsigned __int8 *)(v7 + 332) )
    {
      dev_err(a1, "Select link list to program using curr_list\n");
      v9 = -22;
    }
    else
    {
      if ( v8 == 3 && v11 == 1 )
        v11 = 1;
      v9 = dcc_add_write(v7, v13, v12);
      if ( !v9 )
      {
        mutex_unlock(v7 + 24);
        goto LABEL_9;
      }
    }
  }
  mutex_unlock(v7 + 24);
  a4 = v9;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return a4;
}
