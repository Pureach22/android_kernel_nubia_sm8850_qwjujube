__int64 deinit_tasklet_workers()
{
  cancel_work_sync(&unk_786BE8);
  cancel_work_sync(&unk_786C28);
  cancel_work_sync(&unk_786C68);
  cancel_work_sync(&unk_786CA8);
  cancel_work_sync(&unk_786CE8);
  cancel_work_sync(&unk_786D28);
  cancel_work_sync(&unk_786D68);
  cancel_work_sync(&unk_786DA8);
  cancel_work_sync(&unk_786DE8);
  cancel_work_sync(&unk_786E28);
  cancel_work_sync(&unk_786E68);
  return cancel_work_sync(&unk_786EA8);
}
