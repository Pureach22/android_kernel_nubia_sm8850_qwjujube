__int64 __fastcall fastrpc_wait_for_completion(
        __int64 result,
        _DWORD *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  unsigned int v6; // w28
  unsigned int v7; // w20
  __int64 v9; // x19
  unsigned __int64 StatusReg; // x22
  int v11; // w8
  unsigned int v12; // w25
  char v13; // w27
  __int64 v14; // x8

  v6 = *(_DWORD *)(result + 56);
  v7 = a3;
  v9 = result;
  StatusReg = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v11 = *(_DWORD *)(v9 + 100);
    if ( v11 > 1 )
    {
      if ( v11 == 5 )
      {
        result = poll_for_remote_response(v9, *(unsigned int *)(*(_QWORD *)(v9 + 184) + 288LL));
        if ( (_DWORD)result )
          *(_DWORD *)(v9 + 100) = 0;
        else
          *a2 = 0;
        goto LABEL_3;
      }
      if ( v11 != 3 )
      {
        if ( v11 != 2 )
          goto LABEL_27;
        ++*(_DWORD *)(StatusReg + 16);
        if ( v6 > 0x1F3 )
        {
          v13 = 0;
        }
        else
        {
          v12 = -1;
          do
          {
            result = try_wait_for_completion(v9 + 112);
            v13 = result;
            if ( (result & 1) != 0 )
              break;
            result = _const_udelay(4295);
            ++v12;
          }
          while ( v12 < 0x1F3 );
        }
        v14 = *(_QWORD *)(StatusReg + 16) - 1LL;
        *(_DWORD *)(StatusReg + 16) = v14;
        if ( v14 && *(_QWORD *)(StatusReg + 16) )
        {
          if ( (v13 & 1) != 0 )
            goto LABEL_3;
        }
        else
        {
          result = preempt_schedule();
          if ( (v13 & 1) != 0 )
            goto LABEL_3;
        }
      }
      goto LABEL_24;
    }
    if ( v11 )
      break;
LABEL_24:
    result = fastrpc_wait_for_response(v9, v7);
    *a2 = result;
    if ( (_DWORD)result || (*(_BYTE *)(v9 + 96) & 1) != 0 )
      return result;
LABEL_3:
    if ( *(_BYTE *)(v9 + 96) == 1 )
      return result;
  }
  if ( v11 != 1 )
  {
LABEL_27:
    *a2 = -53;
    result = printk(&unk_26964, *(unsigned int *)(v9 + 100), a3, a4, a5, a6);
    goto LABEL_3;
  }
  result = poll_for_remote_response(v9, 4000);
  if ( (_DWORD)result )
  {
    if ( (*(_BYTE *)(v9 + 96) & 1) != 0 )
      goto LABEL_3;
    goto LABEL_24;
  }
  *(_BYTE *)(v9 + 96) = 1;
  return result;
}
