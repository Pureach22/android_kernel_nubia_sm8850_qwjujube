__int64 __fastcall spr_config_store(__int64 a1, int a2, char *s, int a4)
{
  __int64 v4; // x20
  __int64 v6; // x19
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 *v9; // x9
  __int64 v10; // x10
  __int64 v11; // x9
  __int64 v12; // x9
  __int64 result; // x0
  __int64 v14; // x0
  __int64 v15; // [xsp+0h] [xbp-10h] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  LODWORD(v4) = a4;
  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 152);
  v15 = 0;
  if ( sscanf(s, "%d %d", (char *)&v15 + 4, &v15) != 2 )
  {
    result = -22;
    goto LABEL_13;
  }
  if ( !v6 )
  {
    result = -14;
    goto LABEL_13;
  }
  if ( (unsigned int)v15 >= 8 )
  {
    dev_err(a1, "Input the wrong CPU number\n");
    result = -22;
    goto LABEL_13;
  }
  v7 = mutex_lock(v6);
  if ( (unsigned int)v15 < 8 )
  {
    v8 = v6 + 64;
    v9 = *(__int64 **)(v6 + 64 + 8LL * (unsigned int)v15);
    if ( !v9 )
    {
LABEL_9:
      v4 = (int)v4;
LABEL_10:
      mutex_unlock(v6);
      result = v4;
LABEL_13:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    if ( *((_DWORD *)v9 + 2) <= (unsigned int)(*((_DWORD *)v9 + 4) + 12) )
    {
      dev_err(a1, "Couldn't add SPR config, no enough memory\n");
      v4 = -12;
      goto LABEL_10;
    }
    v10 = *((unsigned int *)v9 + 3);
    v11 = *v9;
    *(_DWORD *)(v11 + 12) = 4 * v10 + 28;
    *(_QWORD *)(v11 + 4 * v10 + 20) = HIDWORD(v15);
    v12 = (unsigned int)v15;
    if ( (unsigned int)v15 <= 7 )
    {
      ++*(_DWORD *)(*(_QWORD *)(v8 + 8LL * (unsigned int)v15) + 12LL);
      *(_DWORD *)(*(_QWORD *)(v8 + 8 * v12) + 16LL) += 12;
      goto LABEL_9;
    }
  }
  __break(0x5512u);
  v14 = MEMORY[0x710EB64](v7);
  return sprs_register_reset_store(v14);
}
