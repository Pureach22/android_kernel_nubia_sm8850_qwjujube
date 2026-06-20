__int64 __fastcall gh_hvc_get_chars(int a1, __int64 a2, unsigned int a3)
{
  unsigned int v3; // w22
  __int64 v7; // x0
  char *v8; // x8
  __int64 v9; // x22
  unsigned int v10; // w19

  v3 = a1 - 1196317000;
  if ( (unsigned int)(a1 - 1196317000) > 4 )
    return -22;
  v7 = raw_spin_lock_irqsave(&fifo_lock);
  v8 = (char *)&gh_hvc_data + 2144 * v3;
  v9 = v7;
  v10 = _kfifo_out(v8 + 16, a2, a3);
  raw_spin_unlock_irqrestore(&fifo_lock, v9);
  return v10;
}
