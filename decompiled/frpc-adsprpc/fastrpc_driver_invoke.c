__int64 __fastcall fastrpc_driver_invoke(__int64 a1, int a2, __int64 *a3)
{
  switch ( a2 )
  {
    case 3:
      return fastrpc_dev_get_hlos_pid(a1, a3);
    case 2:
      return fastrpc_dev_unmap_dma(a1, a3);
    case 1:
      return fastrpc_dev_map_dma(a1, (__int64)a3);
  }
  return -25;
}
