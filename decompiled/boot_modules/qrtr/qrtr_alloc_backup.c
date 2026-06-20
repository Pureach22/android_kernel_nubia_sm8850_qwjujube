void qrtr_alloc_backup()
{
  __int64 v0; // x0
  __int64 v1; // x0
  int v2; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v3; // [xsp+8h] [xbp-8h]

  v3 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = 0;
  if ( (unsigned int)qword_D900 <= 0x13 )
  {
    do
    {
      v0 = alloc_skb_with_frags(32, 1024, 0, &v2, 3264);
      if ( !v0 )
        break;
      skb_queue_tail(&qrtr_backup_lo, v0);
    }
    while ( (unsigned int)qword_D900 < 0x14 );
  }
  if ( (unsigned int)qword_D918 <= 4 )
  {
    do
    {
      v1 = alloc_skb_with_frags(32, 0x4000, 0, &v2, 3264);
      if ( !v1 )
        break;
      skb_queue_tail(&qrtr_backup_hi, v1);
    }
    while ( (unsigned int)qword_D918 < 5 );
  }
  _ReadStatusReg(SP_EL0);
}
