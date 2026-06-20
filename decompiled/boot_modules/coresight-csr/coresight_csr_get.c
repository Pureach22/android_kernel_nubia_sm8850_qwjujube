__int64 __fastcall coresight_csr_get(const char *a1)
{
  __int64 v2; // x19
  _UNKNOWN **v3; // x22
  __int64 v4; // x20

  v2 = raw_spin_lock_irqsave(&csr_spinlock);
  v3 = &csr_list;
  while ( 1 )
  {
    v3 = (_UNKNOWN **)*v3;
    if ( v3 == &csr_list )
      break;
    if ( !strcmp((const char *)*(v3 - 1), a1) )
    {
      v4 = (__int64)(v3 - 1);
      goto LABEL_6;
    }
  }
  v4 = -22;
LABEL_6:
  raw_spin_unlock_irqrestore(&csr_spinlock, v2);
  return v4;
}
