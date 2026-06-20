__int64 __fastcall sg_finish_rem_req(__int64 a1)
{
  __int64 v2; // x21
  unsigned int v3; // w20
  __int64 v4; // x0
  unsigned __int64 v5; // x21

  v2 = *(_QWORD *)(a1 + 16);
  if ( *(_QWORD *)(a1 + 256) )
  {
    v3 = blk_rq_unmap_user();
    if ( !*(_QWORD *)(a1 + 248) )
      goto LABEL_4;
    goto LABEL_3;
  }
  v3 = 0;
  if ( *(_QWORD *)(a1 + 248) )
LABEL_3:
    blk_mq_free_request();
LABEL_4:
  if ( *(_BYTE *)(a1 + 240) )
  {
    *(_WORD *)(a1 + 24) = 0;
    *(_QWORD *)(a1 + 40) = 0;
    *(_DWORD *)(a1 + 48) = 0;
    *(_QWORD *)(a1 + 28) = 0;
    *(_BYTE *)(a1 + 240) = 0;
    *(_BYTE *)(v2 + 4909) = 0;
  }
  else
  {
    v4 = *(_QWORD *)(a1 + 40);
    if ( v4 && *(_DWORD *)(a1 + 28) && !*(_BYTE *)(a1 + 52) )
    {
      if ( *(_WORD *)(a1 + 24) )
      {
        v5 = 0;
        while ( 1 )
        {
          v4 = *(_QWORD *)(a1 + 40);
          if ( !*(_QWORD *)(v4 + 8 * v5) )
            break;
          _free_pages(*(_QWORD *)(v4 + 8 * v5++), *(unsigned int *)(a1 + 48));
          if ( v5 >= *(unsigned __int16 *)(a1 + 24) )
          {
            v4 = *(_QWORD *)(a1 + 40);
            break;
          }
        }
      }
      kfree(v4);
    }
    *(_QWORD *)(a1 + 40) = 0;
    *(_QWORD *)(a1 + 48) = 0;
    *(_QWORD *)(a1 + 24) = 0;
    *(_QWORD *)(a1 + 32) = 0;
  }
  return v3;
}
