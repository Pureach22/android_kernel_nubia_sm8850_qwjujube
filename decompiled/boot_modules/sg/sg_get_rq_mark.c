__int64 *__fastcall sg_get_rq_mark(__int64 a1, int a2, _BYTE *a3)
{
  __int64 v6; // x1
  __int64 *v7; // x20

  *a3 = 0;
  v6 = raw_write_lock_irqsave(a1 + 48);
  v7 = *(__int64 **)(a1 + 144);
  if ( v7 == (__int64 *)(a1 + 144) )
  {
LABEL_11:
    v7 = nullptr;
    goto LABEL_12;
  }
  while ( 1 )
  {
    if ( *((_BYTE *)v7 + 242) || a2 != -1 && *((_DWORD *)v7 + 26) != a2 )
      goto LABEL_4;
    if ( *((_BYTE *)v7 + 243) )
      break;
    *a3 = 1;
LABEL_4:
    v7 = (__int64 *)*v7;
    if ( v7 == (__int64 *)(a1 + 144) )
      goto LABEL_11;
  }
  if ( *((_BYTE *)v7 + 243) != 1 )
    goto LABEL_4;
  *((_BYTE *)v7 + 243) = 2;
LABEL_12:
  raw_write_unlock_irqrestore(a1 + 48, v6);
  return v7;
}
