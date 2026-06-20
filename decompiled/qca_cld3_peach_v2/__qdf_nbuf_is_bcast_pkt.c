bool __fastcall _qdf_nbuf_is_bcast_pkt(__int64 a1)
{
  int *v1; // x8
  int v2; // w9
  int v3; // w8

  v1 = *(int **)(a1 + 224);
  v2 = *v1;
  v3 = *((__int16 *)v1 + 2);
  return v2 == -1 && v3 == -1;
}
