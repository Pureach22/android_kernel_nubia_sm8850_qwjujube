__int64 __fastcall qrtr_port_lookup(int a1)
{
  int v1; // w19
  __int64 v2; // x0
  __int64 v3; // x1
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 v6; // x20
  unsigned int v14; // w8

  if ( a1 == -2 )
    v1 = 0;
  else
    v1 = a1;
  v2 = raw_spin_lock_irqsave(&qrtr_port_lock);
  v3 = v1;
  v4 = v2;
  v5 = xa_load(&qrtr_ports, v3);
  v6 = v5;
  if ( v5 )
  {
    _X0 = (unsigned int *)(v5 + 128);
    __asm { PRFM            #0x11, [X0] }
    do
      v14 = __ldxr(_X0);
    while ( __stxr(v14 + 1, _X0) );
    if ( !v14 || (((v14 + 1) | v14) & 0x80000000) != 0 )
      refcount_warn_saturate();
  }
  raw_spin_unlock_irqrestore(&qrtr_port_lock, v4);
  return v6;
}
