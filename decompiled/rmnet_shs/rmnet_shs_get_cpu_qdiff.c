__int64 __fastcall rmnet_shs_get_cpu_qdiff(unsigned __int8 a1)
{
  if ( a1 > 7u )
    return 0;
  else
    return LODWORD(rmnet_shs_cpu_node_tbl[5 * a1 + 3]);
}
