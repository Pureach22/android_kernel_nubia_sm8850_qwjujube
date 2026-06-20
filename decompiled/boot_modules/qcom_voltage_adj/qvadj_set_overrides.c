__int64 __fastcall qvadj_set_overrides(__int64 a1, unsigned __int8 a2)
{
  int v2; // w20
  unsigned int v3; // w0

  v2 = a2;
  mutex_lock(pd);
  v3 = regmap_write(*(_QWORD *)(pd + 48), 29009, v2 | 0x88u);
  if ( (v3 & 0x80000000) != 0 )
    printk(&unk_65FE, v3);
  mutex_unlock(pd);
  return 0;
}
