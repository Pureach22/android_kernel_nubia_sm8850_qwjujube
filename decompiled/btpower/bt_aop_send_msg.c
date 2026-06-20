__int64 __fastcall bt_aop_send_msg(__int64 a1, __int64 a2)
{
  unsigned int v3; // w0
  unsigned int v5; // w20

  v3 = qmp_send(*(_QWORD *)(a1 + 152), a2, 64);
  if ( (v3 & 0x80000000) == 0 )
    return 0;
  v5 = v3;
  printk(&unk_1358A, a2);
  return v5;
}
