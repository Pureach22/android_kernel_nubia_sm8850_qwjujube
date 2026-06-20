__int64 __fastcall bt_aop_pdc_reconfig(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x20
  unsigned int v4; // w0
  unsigned int v6; // w19

  if ( *(int *)(a1 + 180) < 1 )
    return 0;
  if ( !*(_QWORD *)(a1 + 184) )
    return 0;
  v2 = 0;
  while ( 1 )
  {
    v3 = *(_QWORD *)(*(_QWORD *)(a1 + 184) + 8 * v2);
    v4 = qmp_send(*(_QWORD *)(a1 + 152), v3, 64);
    if ( (v4 & 0x80000000) != 0 )
      break;
    if ( ++v2 >= (unsigned __int64)*(unsigned int *)(a1 + 180) )
      return 0;
  }
  v6 = v4;
  printk(&unk_1358A, v3);
  return v6;
}
