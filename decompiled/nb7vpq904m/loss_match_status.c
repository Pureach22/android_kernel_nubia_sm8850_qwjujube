__int64 __fastcall loss_match_status(__int64 a1)
{
  unsigned __int8 *v1; // x20

  v1 = *(unsigned __int8 **)(a1 + 128);
  seq_write();
  seq_printf(
    a1,
    "Loss Profile Match:\t %d\t %d\t %d\t %d\t%d\t %d\t %d\t %d\n",
    v1[148],
    v1[149],
    v1[150],
    v1[151],
    v1[152],
    v1[153],
    v1[154],
    v1[155]);
  return 0;
}
