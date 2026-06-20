__int64 __fastcall dp_update_vdev_ingress_stats(__int64 result)
{
  *(_QWORD *)(result + 672) += *(_QWORD *)(result + 688)
                             + *(unsigned int *)(result + 764)
                             + *(unsigned int *)(result + 776)
                             + *(unsigned int *)(result + 768)
                             + (unsigned int)(*(_DWORD *)(result + 752)
                                            + *(_DWORD *)(result + 760)
                                            + *(_DWORD *)(result + 756)
                                            + *(_DWORD *)(result + 772))
                             + *(unsigned int *)(result + 780)
                             + (unsigned __int64)*(unsigned int *)(result + 784)
                             + *(unsigned int *)(result + 788);
  return result;
}
