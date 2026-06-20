void __fastcall sub_30E18(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10)
{
  __int64 v10; // x19
  __int64 v11; // x20

  v11 = *(_QWORD *)(a10 + 80);
  *(_QWORD *)(a10 + 80) = &iris_hfi_core_init__alloc_tag_300;
  _kmalloc_noprof(80LL * *(unsigned int *)(*(_QWORD *)(v10 + 2208) + 384LL), 3520);
  *(_QWORD *)(a10 + 80) = v11;
  JUMPOUT(0x307B4);
}
