__int64 __fastcall eq_status(__int64 a1)
{
  unsigned __int8 *v1; // x20

  v1 = *(unsigned __int8 **)(a1 + 128);
  seq_write();
  seq_printf(
    a1,
    "Equalization:\t\t %d\t %d\t %d\t %d\t%d\t %d\t %d\t %d\n",
    v1[132],
    v1[133],
    v1[134],
    v1[135],
    v1[136],
    v1[137],
    v1[138],
    v1[139]);
  return 0;
}
