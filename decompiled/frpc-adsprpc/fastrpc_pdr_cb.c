__int64 __fastcall fastrpc_pdr_cb(__int64 result, __int64 a2, const char **a3, __int64 a4, __int64 a5, __int64 a6)
{
  const char *v6; // x22
  __int64 v8; // x0
  const char **v9; // x21
  const char *v10; // x19
  __int64 v11; // x0
  const char *v12; // x21
  __int64 i; // x20
  const char *v14; // x1

  if ( a3 )
  {
    v6 = a3[6];
    if ( (_DWORD)result == 0x1FFFFFFF )
    {
      result = printk(&unk_24FB8, "fastrpc_pdr_cb", a3[1], *a3, *((_QWORD *)v6 + 3) + 20LL, a6);
      *((_DWORD *)a3 + 10) = 1;
    }
    else if ( (_DWORD)result == 0xFFFFFFF )
    {
      printk(&unk_25861, "fastrpc_pdr_cb", a3[1], *a3, *((_QWORD *)v6 + 3) + 20LL, a6);
      v8 = raw_spin_lock_irqsave(v6 + 51600);
      ++a3[3];
      *((_DWORD *)a3 + 10) = 0;
      *((_DWORD *)a3 + 11) = 0;
      raw_spin_unlock_irqrestore(v6 + 51600, v8);
      v9 = a3;
      v10 = *a3;
      if ( !strcmp(v10, "audio_pdr_adsp") )
      {
        *((_BYTE *)v6 + 51670) = 0;
        v10 = *v9;
      }
      v11 = raw_spin_lock_irqsave(v6 + 51600);
      v12 = *((const char **)v6 + 6456);
      for ( i = v11; v12 != v6 + 51648; v12 = *(const char **)v12 )
      {
        v14 = *((const char **)v12 + 39);
        if ( v14 )
        {
          if ( !strcmp(v10, v14) )
            fastrpc_notify_users((__int64)v12);
        }
      }
      return raw_spin_unlock_irqrestore(v6 + 51600, i);
    }
  }
  return result;
}
