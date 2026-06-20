__int64 __fastcall sub_10C80(__int64 a1)
{
  int v1; // w12

  if ( v1 )
    JUMPOUT(0x41418);
  return qcom_io_pgtable_free_page(a1);
}
