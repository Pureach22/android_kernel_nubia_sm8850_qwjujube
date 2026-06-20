__int64 __fastcall output_comp_status(__int64 a1)
{
  unsigned __int8 *v1; // x20

  v1 = *(unsigned __int8 **)(a1 + 128);
  seq_write();
  seq_printf(
    a1,
    "Output Compression:\t %d\t %d\t %d\t %d\t%d\t %d\t %d\t %d\n",
    v1[140],
    v1[141],
    v1[142],
    v1[143],
    v1[144],
    v1[145],
    v1[146],
    v1[147]);
  return 0;
}
