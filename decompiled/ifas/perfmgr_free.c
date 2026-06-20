void __fastcall perfmgr_free(void *pvBuf, int i32Size)
{
  if ( pvBuf )
    kfree(pvBuf, i32Size);
}
