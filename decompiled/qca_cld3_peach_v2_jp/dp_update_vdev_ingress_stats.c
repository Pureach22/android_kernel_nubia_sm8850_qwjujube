__int64 __fastcall dp_update_vdev_ingress_stats(__int64 result)
{
  *(_QWORD *)(result + 664) += *(_QWORD *)(result + 680)
                             + *(unsigned int *)(result + 756)
                             + *(unsigned int *)(result + 768)
                             + *(unsigned int *)(result + 760)
                             + (unsigned int)(*(_DWORD *)(result + 744)
                                            + *(_DWORD *)(result + 752)
                                            + *(_DWORD *)(result + 748)
                                            + *(_DWORD *)(result + 764))
                             + *(unsigned int *)(result + 772)
                             + (unsigned __int64)*(unsigned int *)(result + 776)
                             + *(unsigned int *)(result + 780);
  return result;
}
