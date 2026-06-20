__int64 __fastcall snd_event_mstr_add_client(_QWORD **a1, __int64 a2, __int64 a3)
{
  _QWORD *v3; // x21
  __int64 result; // x0
  unsigned __int64 v8; // x23
  unsigned __int64 v9; // x8
  unsigned __int64 StatusReg; // x24
  __int64 v11; // x25

  v3 = *a1;
  if ( (unsigned __int64)*a1 >= 0xFFFFFFFFFFFFF001LL )
  {
    result = __ratelimit(&snd_event_mstr_add_client__rs, "snd_event_mstr_add_client");
    if ( (_DWORD)result )
      return printk(&unk_6E5B, "snd_event_mstr_add_client");
    return result;
  }
  if ( !v3 )
  {
    result = _kmalloc_cache_noprof(__ratelimit, 3520, 16);
    v3 = (_QWORD *)result;
    if ( result )
    {
      result = _kmalloc_cache_noprof(printk, 3520, 32);
      v3[1] = result;
      if ( result )
      {
        *a1 = v3;
        v8 = 32;
        goto LABEL_10;
      }
    }
    goto LABEL_15;
  }
  v8 = 32LL * *v3 + 32;
  result = krealloc_noprof(v3[1], v8, 3520);
  if ( !result )
  {
LABEL_15:
    *a1 = (_QWORD *)-12LL;
    return result;
  }
  while ( 1 )
  {
    v3[1] = result;
LABEL_10:
    v9 = 32LL * *v3;
    if ( (v9 & 0x8000000000000000LL) == 0 && v8 >= v9 && v8 - v9 >= 8 )
      break;
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v11 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &snd_event_mstr_add_client__alloc_tag_7;
    v8 = 32LL * *v3 + 32;
    result = krealloc_noprof(v3[1], v8, 3520);
    *(_QWORD *)(StatusReg + 80) = v11;
    if ( !result )
      goto LABEL_15;
  }
  *(_QWORD *)(result + v9) = 0;
  *(_QWORD *)(v3[1] + 32LL * *v3 + 16) = a3;
  *(_QWORD *)(v3[1] + 32LL * (*v3)++ + 24) = a2;
  return result;
}
